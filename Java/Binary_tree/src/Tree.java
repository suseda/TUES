public class Tree
{
    Node root;

    public Tree(Node root)
    {
        this.root = root;
    }

    public void add(int data)
    {
        Node new_node = new Node(data);

        while(root != null)
        {
            if (root.data > new_node.data && root.left == null)
            {
                root.left = new_node;
                break;
            }

            if (root.data > new_node.data)
                root = root.left;

            if (root.data < new_node.data && root.right == null)
            {
                root.right = new_node;
                break;
            }

            if (root.data < new_node.data)
                root = root.right;

            if(root.data == new_node.data)
            {
                System.out.println("This element already exist!");
                break;
            }
        }
    }

    public void print_tree(Node root)
    {
        if(root == null)
            return;
        System.out.print(root.data);
        System.out.print(" ");
        print_tree(root.left);
        print_tree(root.right);
    }
}
