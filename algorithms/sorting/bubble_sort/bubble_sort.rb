# trying to add this to the array prototype itself

class Array
  def bubble_sort
    size.times do |i|
      ((size - 1) - i).times do |j|
        if self[j] > self[j + 1]
          temp = self[j]
          self[j] = self[j + 1]
          self[j + 1] = temp
        end
      end
    end
  end
end

def interact
  puts "What size array do you want?"
  size = gets.chomp.to_i

  arr = []
  puts "Enter the array elements : "
  size.times { arr.push(gets.chomp.to_i) }

  puts "Current array : "
  p arr

  arr.bubble_sort

  puts "Sorted Array : "
  p arr
end

interact