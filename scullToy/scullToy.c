/* ============================================================================
 * Breakable Toy of Char Device Driver Exevise
 * 
 * Reference to Ch3 in Linux Device Driver 3rd
 * This device only considers the basic operation of Char Device Driver,
 * so advanced functions such as ioctl are not shown here.
 * ============================================================================*/

// ======================= Basic kernel and module header =======================
#include <linux/kernel.h>
#include <linux/module.h>
// ======================= Essential Device Driver Include  =====================
#include <linux/fs.h>		
#include <linux/init.h>		//Module Init API
#include <linux/cdev.h>		//Char Device API

#define DEVICE_NAME	"scullToy"

/* ============================================================================
 * Char Device Operation Definition & Implementation
 *   |- Only four required operations are implemented here:
 *     |- open, release, read, write
 * ============================================================================*/

static int scullToy_open(struct inode *inode, struct file *filp)
{
	return 0;
}
static int scullToy_release(struct inode *inode, struct file *filp)
{
	return 0;
}
static ssize_t scullToy_read(struct file *filp, char __user *buff, size_t count, loff_t *f_ops)
{
	return 0;
}
static ssize_t scullToy_write(struct file *flip, const __user *buff, size_t count, loff_t *f_ops)
{
	return 0;
}

struct file_operations scullToy_fops = {			// 初始化file_operations結構
	.owner =	THIS_MODILE,						// 用來連結裝置的functions
	.open =		scullToy_open,
	.release =	scullToy_release,
	.read =		scullToy_read,
	.write =	scullToy_write,
};

/* ============================================================================
 * Module init and exit
 * ============================================================================*/
static int __init scullToy_init(void)
{
	printk(KERN_ALERT "==> SCULLToy: Init...\n");

	return 0;
}


static void __exit scullToy_exit(void)
{
    printk(KERN_ALERT "==> SCULLToy: Exit...\n");
}

module_init(scullToy_init);
module_exit(scullToy_exit);
MODULE_LICENSE("GPL");

