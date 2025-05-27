#include <linux/of_device.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/tty.h>
#include <linux/kmod.h>
#include <linux/gfp.h>
#include <linux/gpio/consumer.h>
#include <linux/platform_device.h>
static int major = 0;
static struct class *gpioctr_class;
static struct gpio_desc *gpioctr_gpio;
static ssize_t gpio_drv_read (struct file *file, char __user *buf, size_t size, loff_t *offs
et)
{
printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
return 0;
}
static ssize_t gpio_drv_write (struct file *file, const char __user *buf, size_t size, loff_
t *offset)
{
int err;
char status;
printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
err = copy_from_user(&status, buf, 1);
gpiod_set_value(gpioctr_gpio, status);
return 1;
}
static int gpio_drv_open (struct inode *node, struct file *file)
{
gpiod_direction_output(gpioctr_gpio, 0);
return 0;
}
static int gpio_drv_close (struct inode *node, struct file *file)
{
printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
return 0;
}
static struct file_operations gpioctr_drv = {
.owner = THIS_MODULE,
.open
.read
= gpio_drv_open,
= gpio_drv_read,
.write = gpio_drv_write,
.release = gpio_drv_close,
};
/* Get GPIO from platform_device
* Tell the kernel about the file_operations structure: register the driver
*/

static int chip_demo_gpio_probe(struct platform_device *pdev)
{
/* Defined in the device tree: gpioctr-gpios=<...>;*/
gpioctr_gpio = gpiod_get(&pdev->dev, "gpioctr", 0);
if (IS_ERR(gpioctr_gpio)) {
dev_err(&pdev->dev, "Failed to get GPIO for led\n");
return PTR_ERR(gpioctr_gpio);
}
/* register file_operations */
major = register_chrdev(0, "myir_gpioctr", &gpioctr_drv); /* /dev/gpioctr */
gpioctr_class = class_create(THIS_MODULE, "myir_gpioctr_class");
if (IS_ERR(gpioctr_class)) {
printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
unregister_chrdev(major, "gpioctr");
gpiod_put(gpioctr_gpio);
return PTR_ERR(gpioctr_class);
}
device_create(gpioctr_class, NULL, MKDEV(major, 0), NULL, "myir_gpioctr%
d", 0);
return 0;
}
static int chip_demo_gpio_remove(struct platform_device *pdev)
{
device_destroy(gpioctr_class, MKDEV(major, 0));
class_destroy(gpioctr_class);
unregister_chrdev(major, "myir_gpioctr");
gpiod_put(gpioctr_gpio);
return 0;
}
static const struct of_device_id myir_gpioctr[] = {
{ .compatible = "myir,gpioctr" },
{ },
};
static struct platform_driver chip_demo_gpio_driver = {
.probe
.remove
.driver
= chip_demo_gpio_probe,
= chip_demo_gpio_remove,
= {
.name = "myir_gpioctr",
.of_match_table = myir_gpioctr,
},
};
static int __init gpio_init(void)
{
int err;
err = platform_driver_register(&chip_demo_gpio_driver);
return err;
}
/* If there is an entry function, there should be an exit function: when the driver is
uninstalled, this exit function will be called
* Uninstall platform_driver
*/
static void __exit gpio_exit(void)
{
	platform_driver_unregister(&chip_demo_gpio_driver);
}
/* Other improvements: provide device information, automatically create device n
odes*/
module_init(gpio_init);
module_exit(gpio_exit);
MODULE_LICENSE("GPL");
