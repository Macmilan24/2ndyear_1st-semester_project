# Define the main game loop
def play_game():
    # Set up the game board
    board = [[" ", " ", " "],
             [" ", " ", " "],
             [" ", " ", " "]]

    # Set up the game variables
    player = "X"
    game_over = False

    # Loop until the game is over
    while not game_over:
        # Handle events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                # Get the coordinates of the mouse click
                mouse_pos = pygame.mouse.get_pos()
                row = mouse_pos[1] // TILE_SIZE
                col = mouse_pos[0] // TILE_SIZE

                # Check if the space is empty and make a move
                if board[row][col] == " ":
                    board[row][col] = player

                    # Check for a winner
                    winner = check_winner(board)
                    if winner:
                        print(winner + " wins!")
                        game_over = True
                    elif check_tie(board):
                        print("It's a tie!")
                        game_over = True
                    else:
                        player = "O" if player == "X" else "X"

        # Draw the board
        draw_board(board)

    # Quit Pygame
    pygame.quit()
