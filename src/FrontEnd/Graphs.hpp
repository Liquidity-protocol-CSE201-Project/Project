#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include <string>

template <typename TX, typename TY>
class Graph {
public:
    Graph();
    Graph(TX &x_axis, TY &y_axis);
    Graph(TX &x_axis, TY &y_axis, std::string &title);
    
    std::string GetTitle();
    TX GetX();
    TY GetY();
    int ExecuteGraph();


private:
    TX x_axis_;
    TY y_axis_;
    std::string title_;

};

#endif
