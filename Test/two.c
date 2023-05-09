#include <stdio.h>
/*           D
            /|\
           / | \
          /  |  \
         A   C   F
        /|\     /|\
       / | \   / | \
      E  H  B R  K  T
*/
int complete_node = 13;
char tree[] = {'\0', 'D', 'A', 'C', 'F', 'E', 'H', 'B','\0','\0','\0', 'R', 'K', 'T'};
int get_right_child(int index)
{
    int toPoint = (3*index)+1;
    printf("Parent: %d : Parent Value: %c : ",index,tree[index]);
    if (tree[index] != '\0' && toPoint <= complete_node){
        printf("Right Child: %d : Right Child Value: %c\n",toPoint,tree[toPoint]);
        return toPoint;
    }
    printf("No Right Child\n");
    return -1;
}
int get_central_child(int index){
    int toPoint = (3*index)+0;
    printf("Parent: %d : Parent Value: %c : ",index,tree[index]);
    if (tree[index] != '\0' && toPoint <= complete_node){
        printf("Central Child: %d : Central Child Value: %c\n",toPoint,tree[toPoint]);
        return toPoint;
    }
    printf("No Central Child\n");
    return -1;
}
int get_left_child(int index)
{
    int toPoint = 3*index-1;
    printf("Parent: %d : Parent Value: %c : ",index,tree[index]);
    if (tree[index] != '\0' && toPoint <= complete_node){
        printf("Left Child: %d : Left Child Value: %c\n",toPoint,tree[toPoint]);
        return toPoint;
    }
    printf("No Left Child\n");
    return -1;
}
void preorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        printf(" %c\n", tree[index]);
        preorder(get_left_child(index));
        preorder(get_central_child(index));
        preorder(get_right_child(index));
    }
}
void postorder(int index)
{
    if (index > 0 && tree[index] != '\0')
    {
        postorder(get_left_child(index));
        postorder(get_central_child(index));
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
    preorder(1);
    printf("\nPreorder done\n");
    postorder(1);
    printf("\n");
    // inorder(1);
    // printf("\n");
    return 0;
}