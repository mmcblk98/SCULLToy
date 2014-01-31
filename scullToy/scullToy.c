// ======================= Basic kernel and module header =======================
#include <linux/kernel.h>
#include <linux/module.h>
// ======================= Essential Device Driver Include  =====================
#include <linux/fs.h>
#include <linux/init.h>

MODULE_LICENSE("Dule BSD/GPL");

/* ============================================================================
 * Char Device Operation Definition & Implementation
 *   |- Only four required operations are implemented here:
 *     |- open, release, read, write
 * ============================================================================*/

static int scullToy_open(struct inode *inode, struct file *filp)
{
}
static int scullToy_release(struct inode *inode, struct file *filp)
{
}
static ssize_t scullToy_read(struct file *filp, char __user *buff, size_t count, loff_t *f_ops)
{
}
static ssize_t scullToy_write(struct file *flip, const __user *buff, size_t count, loff_t *f_ops)
{
}


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

