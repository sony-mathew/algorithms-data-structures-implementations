class Array

  def swap(a, b)
    temp = self[a]
    self[a] = self[b]
    self[b] = temp
  end

  def partition(l, n)
    x = self[n]
    i = l - 1

    (l..(n-1)).each do |j|
      if self[j] <= x
        i += 1
        swap(j, i)
      end
    end

    swap(i + 1, n)

    return i + 1
  end

  public

    def quick_sort!(l = 0, n = size - 1)
      if l < n
        m = partition(l, n)
        quick_sort!(l, m - 1)
        quick_sort!(m + 1, n)
      end
    end
end

a = [32, 45, 50, 1, -4, 67, 8, 49]
a.quick_sort!
puts a.inspect