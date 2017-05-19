class Solution {
public:
    struct Node {
        long long left, right;
        Node *l_child, *r_child;
        int lazy_tag;
        int value;
        Node() : l_child(NULL), r_child(NULL), left(-1), right(-1), lazy_tag(0), value(0) {}
    };
    struct Tuple {
        long long left, right, height;
        Tuple(long long l, long long r, long long h): left(l), right(r), height(h) {}
        Tuple() {}
    };
    Node *build_tree(long long from, long long to) {
        if (from > to) return NULL;
        Node *root = new Node();
        root->left = from;
        root->right = to;
        root->l_child = NULL;
        root->r_child = NULL;
        root->lazy_tag = 1;
        root->value = 0;
        return root;
    }
    void release_tree(Node *root) {
        if (root == NULL) return;
        release_tree(root->l_child);
        release_tree(root->r_child);
        delete root;
    }
    void range_set(Node *root, int v, long long from, long long to) {
        if (!root) return;
        if (to < root->left || from > root->right) return;
        // printf("root[%d,%d]\n", root->left, root->right);
        if (from <= root->left && to >= root->right) {
            if (root->lazy_tag == 1 && v > root->value) {
                root->value = v;
            } else if (root->lazy_tag == 1 && v <= root->value) {
                // nothing
            } else if (root->lazy_tag == 0) {
                range_set(root->l_child, v, from, to);
                range_set(root->r_child, v, from, to);
            }
        } else {
            if (root->lazy_tag) {
                if (root->left != root->right) {
                    long long pivot = (root->left+root->right)/2;
                    root->l_child = build_tree(root->left, pivot);
                    root->r_child = build_tree(pivot+1,root->right);
                }
                if (root->l_child) {
                    root->l_child->value = root->value;
                    root->l_child->lazy_tag = 1;
                }
                if (root->r_child) {
                    root->r_child->value = root->value;
                    root->r_child->lazy_tag = 1;
                }
            }
            range_set(root->l_child, v, from, to);
            range_set(root->r_child, v, from, to);
            root->lazy_tag = 0;
        }
    }

    void merge(Node *root) {
        if (!root) return;
        if (!root->l_child || !root->r_child) {
            root->lazy_tag = 1;
            return;
        }
        if (root->lazy_tag) return;
        merge(root->l_child);
        merge(root->r_child);
        int lvalue = -1, rvalue = -1;
        if (root->l_child->lazy_tag) {
            lvalue = root->l_child->value;
        }
        if (root->r_child->lazy_tag) {
            rvalue = root->r_child->value;
        }
        if (lvalue >= 0 && lvalue == rvalue) {
            root->lazy_tag = 1;
            root->value = lvalue;
        } else {
            root->lazy_tag = 0;
        }
    }
    void gather(Node *root, std::vector<Tuple> &res) {
        if (!root) return;
        if (root->lazy_tag) {
            res.push_back(Tuple(root->left, root->right, root->value));
            return;
        }
        if (root->l_child) gather(root->l_child, res);
        if (root->r_child) gather(root->r_child, res);
    }

    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        std::vector<std::pair<int,int> > ret;
        int n_building = buildings.size();
        if (n_building == 0) {
            return ret;
        }
        long long right_bound = 0;
        for (int i = 0; i < n_building; i++) {
            if (buildings[i][1] > right_bound) right_bound = buildings[i][1];
        }
        right_bound += 0;
        Node *root = build_tree(0,right_bound);
        merge(root);
        for (int i = 0; i < n_building; i++) {
            range_set(root, buildings[i][2], buildings[i][0], buildings[i][1]);
            merge(root);
        }
        std::vector<Tuple> tup;
        gather(root, tup);
        std::vector<Tuple> segs;
        int last_height = 0;
        segs.push_back(Tuple(0,0,0));
        for (int i = 0; i < tup.size(); i++) {
            if (tup[i].height == last_height) segs.back().right = tup[i].right;
            else segs.push_back(tup[i]);
            last_height = tup[i].height;
        }
        segs.push_back(Tuple(tup.back().right, tup.back().right, 0));
        for (int i = 1; i < segs.size(); i++) {
            if (segs[i].height > segs[i-1].height) {
                ret.push_back(pair<int, int>(segs[i].left, segs[i].height));
            } else {
                ret.push_back(pair<int, int>(segs[i-1].right, segs[i].height));
            }
        }
        return ret;
    }
};
