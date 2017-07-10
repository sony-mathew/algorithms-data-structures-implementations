module Heap

  def max_heapify(heapsize, i)
    l = 2*i + 1
    r = l + 1
    largest = i

    if l < heapsize && self[l] > self[largest]
      largest = l
    end

    if r < heapsize && self[r] > self[largest]
      largest = r
    end

    if largest != i
      swap(i, largest)
      max_heapify(heapsize, largest)
    end
  end

  def build_max_heap
    for i in (0..(size/2 - 1)).to_a.reverse
      max_heapify(size, i)
    end
  end
end

class Array

  include Heap

  def swap(i, j)
    temp = self[i]
    self[i] = self[j]
    self[j] = temp
  end

  public

    def heap_sort!
      build_max_heap
      for i in (0..(size - 1)).to_a.reverse
        swap(0, i)
        max_heapify(i, 0)
      end
    end
end

def interact
  puts "What size array do you want ? "
  size = gets.chomp.to_i

  array = []
  puts "Enter the array elements : "
  size.times { array.push(gets.chomp.to_i) }

  puts "Current array : "
  puts array.inspect

  array.heap_sort!

  puts "Sorted array : "
  puts array.inspect
end

interact