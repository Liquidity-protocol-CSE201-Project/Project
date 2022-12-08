#include "Graphs.hpp"
using namespace std;

template <typename TX, typename TY>
Graph<TX, TY>::Graph() {
    x_axis_ = NULL;
    y_axis_ = NULL;
    title_ = nullptr;
};
template <typename TX, typename TY>
Graph<TX, TY>::Graph(TX &x_axis, TY &y_axis) {
    x_axis_ = x_axis;
    y_axis_ = y_axis;
    title_ = nullptr;
};
template <typename TX, typename TY>
Graph<TX, TY>::Graph(TX &x_axis, TY &y_axis, std::string &title) {
    x_axis_ = x_axis;
    y_axis_ = y_axis;
    title_ = title;
};
