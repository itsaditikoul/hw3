#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator())
    : m_(m), comp_(c) {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item) {
    data_.push_back(item);
    trickleUp(data_.size()-1);
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const {
    if (empty()) {
      throw std::underflow_error("top on empty heap");
    }
    return data_[0];

  }

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop() {
    if (empty()) {
      throw std::underflow_error("pop on empty heap");
    }
      std::swap(data_.front(), data_.back());
      data_.pop_back();
      if (!empty()) {
        trickleDown(0);
      }
  }

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const {return data_.empty(); }

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const {return data_.size(); };

private:
  /// Add whatever helper functions and data members you need below

  size_t parent(size_t i) const {return (i - 1)/ m_; }
  size_t kthChild(size_t i, int k) const { return m_*i +k;} // k=1..m_

  void trickleUp(size_t i) {
    while(i> 0) {
      size_t p = parent(i);
      if (comp_(data_[i], data_[p])) {
        std::swap(data_[i], data_[p]);
        i=p;
      } else break;
    }
  }


  void trickleDown(size_t i) {
    while (true) {
      size_t best = i;


      for (int k = 1; k<=m_; ++k) {
        size_t c = kthChild(i,k);
        if (c>=data_.size()) break;
        if(comp_(data_[c], data_[best])) best = c;
      }

      if (best!=i) {
        std::swap(data_[i], data_[best]);
        i=best;
      } else break;

    }
  }

  int m_;
  PComparator comp_;
  std::vector<T> data_;




};


/*
// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================


  }



}

*/

#endif

