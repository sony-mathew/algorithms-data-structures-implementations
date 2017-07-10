class Array
  def merge_sort!(x = 0, z = (size - 1))
    if x < z
      y = (x + z)/2
      merge_sort!(x, y)
      merge_sort!(y + 1, z)
      array_merge(x, y, z)
    end
  end

  def array_merge(x, y, z)
    n1 = y - x + 1
    n2 = z - y

    l = self[x...(x + n1)]
    m = self[(y + 1)...(y + 1 + n2)]

    i, j = [0, 0]
    (x..z).each do |k|
      if (i < n1) && ((j >= n2) || (l[i] <= m[j]))
        self[k] = l[i]
        i += 1
      else
        self[k] = m[j]
        j += 1
      end
    end
  end
end

def interact
  puts "What size array do you want? "
  size = gets.chomp.to_i

  array = []
  puts "Enter the array : "
  size.times { array.push(gets.chomp.to_i) }

  puts "Current array : "
  puts array.inspect

  array.merge_sort!

  puts "Sorted array : "
  puts array.inspect
end

interact
