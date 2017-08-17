class Solution {
public:
    int first_digit(int x) {
        while (x >= 10) {
            x /= 10;
        }
        return x;
    }
    int num_digit(int x) {
        int n = 0;
        while (x) {
            x /= 10;
            n++;
        }
        return n;
    }
    int all_1(int num_digit) {
        int s = 1;
        for (int i = 0; i < num_digit - 1; i++) {
            s = s*10 + 1;
        }
        return s;
    }
    struct Node {
        int node_size;
        int depth;
        int is_full;
        Node *child[10];
    };
    Node* expand_node(int n, int digit) {
        Node *node = new Node;
        node->is_full = false;
        node->node_size = n;
        node->depth = digit;
        if (n <= 1) return node;
        if (digit - 2 <= 0) return node;
        int batch_size = all_1(digit - 1);
        int batch_size2 = all_1(digit-2);
        int pos = 0;
        int not_full_id = (n - 1 - batch_size2*10) / (batch_size - batch_size2);
        for (int i = 0; i < not_full_id; i++) {
            node->child[i] = new Node;
            node->child[i]->is_full = true;
            node->child[i]->depth = digit - 1;
            node->child[i]->node_size = batch_size;
        }
        for (int i = not_full_id + 1; i <= 9; i++) {
            node->child[i] = new Node;
            node->child[i]->is_full = true;
            node->child[i]->depth = digit - 2;
            node->child[i]->node_size = batch_size2;
        }
        int not_full_size = n - 1 - (not_full_id)*batch_size - (9 - not_full_id)*batch_size2;
        node->child[not_full_id] = expand_node(not_full_size, digit - 1);
        return node;
    }
    void find(Node *node, int k, std::vector<int> &res) {
        if (node->depth == 1) return;
        if (node->depth == 2) {
            if (k > 0) res.push_back(k-1);
            return;
        }
        if (node->is_full) {
            int cur_dig = node->depth - 1;
            int rem = k;
            while (rem) {
                int cur_batch = all_1(cur_dig);
                res.push_back((rem - 1)/cur_batch);
                rem = (rem - 1) % cur_batch;
                cur_dig -= 1;
            }
        } else {
            if (k == 0) return;
            k--;
            int s = 0;
            int idx = -1;
            int rem = -1;
            for (int i = 0; i <= 9; i++) {
                if (s <= k && k < node->child[i]->node_size + s) {
                    idx = i;
                    rem = k - s;
                    break;
                }
                s += node->child[i]->node_size;
            }
            res.push_back(idx);
            find(node->child[idx], rem, res);
        }
    }
    int findKthNumber(int n, int k) {
        if (n < 10) return k;
        int n_digi = num_digit(n);
        int first_digi = first_digit(n);
        int res = 0;
        int batch_size = all_1(n_digi);
        int batch_size2 = all_1(n_digi-1);
        int not_fulll_size = n - (batch_size*(first_digi-1) + batch_size2*(9-first_digi));
        int res_1 = -1;
        int seg_id = -1;
        int pos = 0;
        k--;
        for (int i = 1; i <= first_digi - 1; i++) {
            if (pos <= k && k < pos + batch_size){
                res_1 = i;
                seg_id = 1;
                break;
            } 
            pos += batch_size;
        }
        std::cout << batch_size << ' ' << first_digi << ' ' << not_fulll_size << std::endl;
        if (seg_id < 0) {
            if (pos <= k && k < pos + not_fulll_size) {
                seg_id = 2;
                res_1 = first_digi;
            } else {
                pos += not_fulll_size;
            }
        }
        if (seg_id < 0) {
            for (int i = first_digi + 1; i <= 9; i++) {
                if (pos <= k && k < pos + batch_size2){
                    res_1 = i;
                    seg_id = 3;
                    break;
                }
                pos += batch_size2;
            }
        }
        Node *nodes[10];
        for (int i = 1; i <= 9; i++) {
            if (i == first_digi) {
                nodes[i] = expand_node(not_fulll_size, n_digi);
                continue;
            }
            nodes[i] = new Node;
            if (i < first_digi){
                nodes[i]->node_size = batch_size;
                nodes[i]->depth = n_digi;
            } else if (i > first_digi) {
                nodes[i]->node_size = batch_size2;
                nodes[i]->depth = n_digi - 1;
            }
            nodes[i]->is_full = true;
        }
        std::vector<int> res_digits;
        res_digits.push_back(res_1);
        find(nodes[res_1], k - pos, res_digits);
        for (int i = 0; i < res_digits.size(); i++) {
            res = res*10 + res_digits[i];
        }
        return res;
    }
};
