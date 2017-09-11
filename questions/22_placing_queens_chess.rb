=begin
place 8 queens on a chessboard without conflicting 8
=end

class PlaceQueen

  attr_accessor :board, :board_cells, :index, :queens_in_row

  def initialize
    @board = []
    @board_cells = []
    @queens_in_row = []
    @index = 3
    board_init
  end

  def place_on(row)
    
    return if row > 7

    8.times do |col|
      new_col = col
      new_col += @index if col == 0
      if @board_cells[row][new_col]
        @board[row][new_col] = 1
        @queens_in_row[row] = true
        invalidate_cells(row, new_col)
        break
      end
    end

    place_on(row + 1)

    # unless validate_placing
    #   board_init
    #   @index += 1
    #   place_on(0)
    # end
  end
  
  private

    def validate_placing
      @queens_in_row.all?
    end

    def board_init
      8.times do |i|
        @queens_in_row[i] = nil
        8.times do |j|
          @board[i] ||= []
          @board_cells[i] ||= []
          @board[i][j] = 0
          @board_cells[i][j] = true
        end
      end
    end

    def invalidate_cells(row, col)

      k = 0
      while (k < 8)
        # marking all row cells & column cells as invalid
        @board_cells[row][k] = false
        @board_cells[k][col] = false

        #mark diagonals as invalid

        #top left to bottom right diagonal - backward slash
        mark_invalid(row + k, col + k)
        mark_invalid(row - k, col - k)
        
        #top right to bottom left diagonal - forward slash
        mark_invalid(row - k, col + k)
        mark_invalid(row + k, col - k)

        k += 1
      end

    end

    def mark_invalid(r, c)
      if r >= 0 && r < 8 && c >= 0 && c < 8
        @board_cells[r][c] = false
      end
    end
end

q = PlaceQueen.new
q.place_on(0)