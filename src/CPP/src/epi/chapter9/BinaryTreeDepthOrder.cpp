#include "BinaryTreeDepthOrder.hpp"

#include <memory>
#include <queue>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "../../MyUtils.h"
#include "../../BinaryTreeNode.h"

using std::queue;
using std::unique_ptr;
using myutils::BinaryTreeNode;
using std::move;
using std::vector;
using std::string;
using myutils::matrix_to_string;
using std::length_error;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter9 {
    vector<vector<int>> BinaryTreeDepthOrder::binaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>> &tree) {
        queue<BinaryTreeNode<int>*> processingNodes;
        processingNodes.push(tree.get());
        size_t levelSize = processingNodes.size();

        vector<vector<int>> res;

        while (!processingNodes.empty()) {
            vector<int> curLevel;
            for (size_t i = 0; i != levelSize; ++i) {
                auto cur = processingNodes.front();
                processingNodes.pop();
                curLevel.push_back(cur->data);

                if (cur->left)
                    processingNodes.push(cur->left.get());
                if (cur->right)
                    processingNodes.push(cur->right.get());
            }

            res.push_back(curLevel);
            levelSize = processingNodes.size();
        }

        return res;
    }

    bool BinaryTreeDepthOrder::test() {
        unique_ptr<BinaryTreeNode<int>> A(new BinaryTreeNode<int>{314});
        unique_ptr<BinaryTreeNode<int>> B(new BinaryTreeNode<int>{6});
        unique_ptr<BinaryTreeNode<int>> C(new BinaryTreeNode<int>{271});
        unique_ptr<BinaryTreeNode<int>> D(new BinaryTreeNode<int>{28});
        unique_ptr<BinaryTreeNode<int>> E(new BinaryTreeNode<int>{0});
        unique_ptr<BinaryTreeNode<int>> F(new BinaryTreeNode<int>{561});
        unique_ptr<BinaryTreeNode<int>> G(new BinaryTreeNode<int>{3});
        unique_ptr<BinaryTreeNode<int>> H(new BinaryTreeNode<int>{17});
        unique_ptr<BinaryTreeNode<int>> I(new BinaryTreeNode<int>{6});
        unique_ptr<BinaryTreeNode<int>> J(new BinaryTreeNode<int>{2});
        unique_ptr<BinaryTreeNode<int>> K(new BinaryTreeNode<int>{1});
        unique_ptr<BinaryTreeNode<int>> L(new BinaryTreeNode<int>{401});
        unique_ptr<BinaryTreeNode<int>> M(new BinaryTreeNode<int>{641});
        unique_ptr<BinaryTreeNode<int>> N(new BinaryTreeNode<int>{257});
        unique_ptr<BinaryTreeNode<int>> O(new BinaryTreeNode<int>{271});
        unique_ptr<BinaryTreeNode<int>> P(new BinaryTreeNode<int>{28});

        L.get()->right = move(M);

        G.get()->left = move(H);
        K.get()->left = move(L);
        K.get()->right = move(N);

        C.get()->left = move(D);
        C.get()->right = move(E);
        F.get()->right = move(G);
        J.get()->right = move(K);
        O.get()->right = move(P);

        B.get()->left = move(C);
        B.get()->right = move(F);
        I.get()->left = move(J);
        I.get()->right = move(O);

        A.get()->left = move(B);
        A.get()->right = move(I);


        vector<vector<int>> res = binaryTreeDepthOrder(A);

        vector<int> ans1 = {314};
        vector<int> ans2 = {6, 6};
        vector<int> ans3 = {271, 561, 2, 271};
        vector<int> ans4 = {28, 0, 3, 1, 28};
        vector<int> ans5 = {17, 401, 257};
        vector<int> ans6 = {641};

        vector<vector<int>> ans = {ans1, ans2, ans3, ans4, ans5, ans6};

        if (res != ans) {
            cout << "Should be:" << endl;
            cout << matrix_to_string(ans) << endl;
            cout << "Result: " << endl;
            cout << matrix_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter9
} // epi
