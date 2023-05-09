#include <stdio.h>
/*           D
            / \
           /   \
          /     \
         A       F
        / \     / \
       /   \   /   \
      E     B R     T
     / \     /     / \
    G   Q   V     J   L
*/
/*
 D
 A
 E
 G
 Q
 B
 F
 R
 V
 T
 J
 L
 */
/*
 G
 Q
 E
 B
 A
 V
 R
 J
 L
 T
 F
 D
*/
int complete_node = 15;
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};
int get_right_child(int index)
{
    if (tree[index] != '\0' && ((2 * index) + 1) <= complete_node)
        return (2 * index) + 1;
    return -1;
}
int get_left_child(int index)
{
    if (tree[index] != '\0' && (2 * index) <= complete_node)
        return 2 * index;
    return -1;
}
void preorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        printf(" %c\n", tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}
void postorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %c\n", tree[index]);
    }
}
void inorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        inorder(get_left_child(index));
        printf(" %c\n", tree[index]);
        inorder(get_right_child(index));
    }
}
int main()
{
    preorder(2);
    printf("\n");
    postorder(1);
    printf("\n");
    inorder(1);
    printf("\n");
    return 0;
}