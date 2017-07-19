class Node
  attr_accessor :data, :next

  def initialize(key = nil, ptr = nil)
    @data = key
    @next = ptr
  end
end

class LinkedList

  attr_accessor :head

  def add key
    new_n = Node.new(key)
    if @head == nil
      @head = new_n
    else
      new_n.next = @head
      @head = new_n
    end
  end

  def remove key
    if @head == nil
      puts "Underflow. LinkedList is empty."
      return
    end

    if @head.data == key
      @head = @head.next
    else
      current = @head
      while current.next != nil
        if current.next.data == key
          current.next = current.next.next
        end
        current = current.next
      end
    end
  end

  def show
    np = @head
    while np != nil
      print "#{np.data}  "
      np = np.next
    end
    print "\n"
  end
end

def interact
  l = LinkedList.new
  l.add(3)
  l.add(6)
  l.add(765)
  l.add(34)
  l.add(-56)
  l.add(91)

  l.show

  l.remove(765)
  l.show

  l.remove(34)
  l.show
end

interact