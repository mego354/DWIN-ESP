This library works on both arduino and ESP 

1. make sure to connect the main rx, tx of the microcontroller to the tx, rx of the screen
2. serial baud must be the same baud of the DGUS project
3. for text displaying, make sure to keep track of the text length every time you write in a vp address to be able to erase it then, otherwise you may have trouble rewrite it again after wrong erasing
4.prevent using Serial println it's sending this data to the screen and it might harm the screen's cpu 

best of luck