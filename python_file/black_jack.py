from importlib.metadata import distribution
import random

# added symbols to the variable
HEARTS=chr(9829)
DIAMONDS=chr(9830)
SPADES=chr(9824)
CLUBS=chr(9827)

# card distribution
card_s=[HEARTS,DIAMONDS,SPADES,CLUBS]
special_card=['A','K','Q','J']
total_cards=[[x,y] for y in special_card for x in card_s]
adding_list=[[x,y] for y in range(2,11) for x in card_s]
total_cards.extend(adding_list)

dealer_card=[]
player_card=[]

# function that give card to the dealer (only one card)
def give_dealer():
    selected_card=random.choice(total_cards)
    dealer_card.append(selected_card)
    total_cards.remove(selected_card)

# function that give card to the player (only one card)
def give_player():
    selected_card=random.choice(total_cards)
    player_card.append(selected_card)
    total_cards.remove(selected_card)

# it checks who won the match
def win_check():
    dealer_card_add=0
    for i in dealer_card:
        if i[1]=='K':
            i[1]=10
        elif i[1]=='J':
            i[1]=10
        elif i[1]=='Q':
            i[1]=10
        elif i[1]=='A':
            i[1]=1
        dealer_card_add+=i[1]
    
    player_card_add=0
    for i in player_card:
        if i[1]=='K':
            i[1]=10
        elif i[1]=='J':
            i[1]=10
        elif i[1]=='Q':
            i[1]=10
        elif i[1]=='A':
            i[1]=1
        player_card_add+=i[1]

    if player_card_add==21:
        return 'P'

    elif player_card_add>21:
        return 'D'

    elif dealer_card_add>21:
        return 'P'

    elif dealer_card_add<16:
        give_dealer()
        win_check()

    elif dealer_card_add==21:
        return 'D'
    
    elif player_card_add>dealer_card_add:
        return 'P'
    
    elif dealer_card_add>player_card_add:
        return 'D'

#  main function to start the game   
def initial_game():
    for _ in range(2):
        give_dealer()
        give_player()

    print(f'Dealer Card: {dealer_card}')
    print(f'Player Card: {player_card}')
    
    while True:
        print('(H)it, (S)tand, (D)ouble down')
        feed=input('> ').lower()

        if feed=='h':
            give_player()
            print(f'Dealer Card: {dealer_card}')
            print(f'Player Card: {player_card}')
            win_check()
            
        elif feed=='s':
            final=win_check()
            print(final)
            if final=='P':
                print('Player Won')
                break
            elif final=='D':
                print('Dealer Won')
                break

        elif feed=='d':
            if win_check()=='P':
                print('Player Won!')
                break

# game play triggered
initial_game()