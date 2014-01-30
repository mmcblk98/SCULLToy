#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dule BSD/GPL");

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

