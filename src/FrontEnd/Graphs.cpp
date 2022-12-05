#include "Graphs.hpp"

template <typename TX, typename TY>
Graph<TX, TY>::Graph() {
    x_axis_ = none;
    y_axis_ = none;
    title_ = none;
};
template <typename TX, typename TY>
Graph<TX, TY>::Graph(TX &x_axis, TY &y_axis) {
    x_axis_ = x_axis;
    y_axis_ = y_axis;
    title_ = none;
};
template <typename TX, typename TY>
Graph<TX, TY>::Graph(TX &x_axis, TY &y_axis, std::string &title) {
    x_axis_ = x_axis;
    y_axis_ = y_axis;
    title_ = title;
};
