//
// Created by jlibyvali on 24-3-30.
//

#ifndef CHAPTER12_GRID_H
#define CHAPTER12_GRID_H

#include <optional>
#include <vector>
#include <stdexcept>
#include <utility>
#include <string>
#include <algorithm>

// Template friend
template<typename T> class Grid;    // Forward declare Grid templates

template<typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs);  // Declare operator as function here;


template<typename T>
class Grid {
public:

    static const int defaultWidth{10};
    static const int defaultHeight{10};

    explicit Grid(int width = defaultWidth, int height = defaultHeight);

    virtual  ~Grid() = default;

    Grid(const Grid& src) = default;
    Grid&operator=(const Grid& src) = default;


    // method template, CAN'T DEL Original method,
    // if " E == T ", Compiler will not call these " template method"
    template<typename E>    // template to method, when E==T, it's equal.
    Grid(const Grid<E> &src);

    template<typename E>
    Grid &operator=(const Grid<E> &src);

    void swap(Grid& other) noexcept;

    Grid(Grid &&rhs) = default;
    Grid &operator=(Grid &&rhs) = default;

    std::optional<T> &at(size_t x, size_t y);
    const std::optional<T> &at(size_t x, size_t y) const;


    size_t getHeight() const { return m_height; }
    size_t getWidth() const { return m_width; }


// Template friend
    friend Grid<T>  operator+<T>(const Grid& lhs, const Grid& rhs); // Mark the "operator" func as "friend" , so that 'operator+' can visit priate:
    /*The template friend syntax get a little bit.
     * but it also indicates:
     * There exist "one-to-one" mapping relationship between class instance and function instance in template.
     * */


private:
    void verify(size_t x, size_t y) const;

    std::vector<std::vector<std::optional<T> > > m_cells;
    size_t m_width{0}, m_height{0};

};

template<typename T>
Grid<T>::Grid(int width, int height) : m_width(width), m_height(height) {

    m_cells.resize(m_width);
    for (auto &ele: m_cells) {
        ele.resize(m_height);
    }
}

template<typename T>
void Grid<T>::verify(size_t x, size_t y) const {
    if (x >= m_width || y >= m_height) {
        throw std::out_of_range(" x or y is out of range value;");
    }
}


template<typename T>
const std::optional<T> &Grid<T>::at(size_t x, size_t y) const {
    verify(x, y);
    return m_cells[x][y];
}

template<typename T>
std::optional<T> &Grid<T>::at(size_t x, size_t y) {
    return const_cast< std::optional<T> & > (std::as_const(*this).at(x, y));
}


// For method template!!!
template<typename T>
template<typename E>
Grid<T>::Grid(const Grid<E>& src) : Grid( src.m_width, src.m_height) {

        for(size_t i=0;i<m_width;i++){
            for(size_t j=0;j<m_height;j++){
                m_cells[i][j] = src.at(i,j);
            }
        }
}

template<typename T>
void Grid<T>::swap(Grid &other) noexcept {
    std::swap(m_width,other.m_width);
    std::swap(m_height,other.m_height);
    std::swap(m_cells,other.m_cells);
}

template<typename T>
template<typename  E>
Grid<T>& Grid<T>::operator=(const Grid<E> &src) {
    Grid<T> tmp { src };    // src was Grid<E>& but return Grid<T>& ok, case tmp will call src's ctor first.
    swap(tmp);
    return  *this;
}


/*Template Specialization
 *
 * "Specialization" is different from Inherit.
 * didn't inherit any method.
 * */

template <>
class Grid<const char*>{

public:

    static const int defaultWidth{10};
    static const int defaultHeight{10};

    explicit Grid(int width = defaultWidth, int height = defaultHeight);

    virtual  ~Grid() = default;

    Grid(const Grid &src) =default;

    Grid &operator=(const Grid &src) = default;

    void swap(Grid& other) noexcept;

    Grid(Grid &&rhs) = default;

    Grid &operator=(Grid &&rhs) = default;

    std::optional<std::string > &at(size_t x, size_t y);
    const std::optional<std::string> &at(size_t x, size_t y) const;


    size_t getHeight() const { return m_height; }
    size_t getWidth() const { return m_width; }

private:
    void verify(size_t x, size_t y) const;

    std::vector<std::vector<std::optional<std::string> > > m_cells;
    size_t m_width{0}, m_height{0};
};

Grid<const char*>::Grid(int width, int height) : m_width(width),m_height(height){

    m_cells.resize(m_width);

    for(auto& ele : m_cells){
        ele.resize(m_height);
    }

}
#endif //CHAPTER12_GRID_H
