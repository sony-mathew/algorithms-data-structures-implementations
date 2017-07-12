
class Node
  attr_accessor :data, :next
end

class Stack

  attr_accessor :top

  def push(item)
    n = Node.new
    n.data = item
    
    if @top
      temp = @top
      @top = n
      @top.next = temp
    else
      @top = n
    end
  end

  def pop
    if @top
      d = @top.data
      @top = @top.next
    else
      puts "Stack is empty."
      d = -1
    end
    d
  end

  def show
    top_itr = @top
    while(top_itr)
      print "#{top_itr.data} "
      top_itr = top_itr.next
    end
    print "\n"
  end
end

def interact
  s = Stack.new
  s.push(34)
  s.push(987)

  s.show

  s.push(-45)
  s.push(87)
  s.push(5)

  s.show

  s.pop
  s.show
end

interact