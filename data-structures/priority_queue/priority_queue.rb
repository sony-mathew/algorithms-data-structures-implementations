class MaxHeap

  attr_accessor :array, :size

  def initialize(arr)
    @size = 0
    build_heap(arr)
  end

  def max
    if @size < 1
      puts "Underflow"
      return
    end
    @array[0]
  end

  def extract_max
    if @size < 1
      puts "Underflow"
      return
    end

    max = @array[0]
    @array[0] = @array.pop()
    @size -= 1

    heapify(0)

    max
  end

  def insert(key)
    @array[size] = key
    @size += 1
    increase_key(@size - 1, key)
  end

  private

    def swap(a, b)
      temp = @array[a]
      @array[a] = @array[b]
      @array[b] = temp
    end

    def heapify(i)
      l = 2*i + 1
      r = l + 1
      largest = i

      largest = l if (l < @size && @array[l] > @array[largest])
      largest = r if (r < @size && @array[r] > @array[largest])

      if largest != i
        swap(i, largest)
        heapify(largest)
      end
    end

    def build_heap arr
      @size = arr.size
      @array = arr
      (0..(@size/2 -1)).to_a.reverse.each { |j| heapify(j) }
    end

    def increase_key(i, key)
      if (key < @array[i])
        puts "New key is less than existing key."
        return
      end

      @array[i] = key
      parent = i/2

      while(i > 0 && @array[parent] < @array[i])
        swap(i, parent)
        i = parent
        parent = i/2
      end
    end
end

def interact
  arr = [21, 3, 34, 56, 78, 11, 6, 90, 19, 87]

  h = MaxHeap.new(arr)
  
  puts "Heap array : "
  puts h.array.inspect

  h.insert(141)
  puts "Heap array after inserting 141: "
  puts h.array.inspect

  puts "Max : #{h.max}"
  puts "Extract max : #{h.extract_max}"

  puts "Heap array after extracting max : "
  puts h.array.inspect
end

interact