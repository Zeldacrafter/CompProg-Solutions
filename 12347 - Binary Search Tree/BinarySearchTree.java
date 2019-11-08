import java.util.Scanner;

public class BinarySearchTree {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        Node root = null;
        // Creating the tree could be done faster by using the rule with which
        // the input is generated. But this one is fast enough and way simpler.
        while(s.hasNext()) {

            int val = s.nextInt();

            if(root == null)
                root = new Node(null, val);
            else {
                Node currNode = root;
                while(true) {
                    if(currNode.value > val) {
                        if (currNode.left != null) {
                            currNode = currNode.left;
                        } else {
                            currNode.left = new Node(currNode, val);
                            break;
                        }
                    }else {
                        if (currNode.right != null) {
                            currNode = currNode.right;
                        } else {
                            currNode.right = new Node(currNode, val);
                            break;
                        }
                    }
                }
            }
        }

        if(root != null)
            postOrder(root);

        s.close();
    }

    static void postOrder(Node n) {
        Node curr = n;
        while(true) {
            //Go to lower left
            while (curr.left != null || curr.right != null) {
                while (curr.left != null)
                    curr = curr.left;
                if (curr.right != null)
                    curr = curr.right;
            }
            System.out.println(curr.value);
            while(!curr.isRoot()) {
                if (curr.parent.right != null && !curr.parent.right.equals(curr)) {
                    curr = curr.parent.right;
                    break;
                } else {
                    curr = curr.parent;
                    System.out.println(curr.value);
                }
            }
            if(curr.isRoot()) break;
        }
    }

    private static class Node {
        Node left, right, parent;
        int value;

        public Node(Node parent, int value) {
            this.parent = parent;
            this.value = value;
        }

        boolean isRoot() { return parent == null; }
    }
}