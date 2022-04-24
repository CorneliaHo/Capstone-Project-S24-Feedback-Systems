import time
from playsound2 import playsound

initial_time = time.time() # start time
i = 1 # question count

print('You have started the test. Question 1 will play after 10 seconds.')

while i < 11:
    current_time = time.time()
    elasped_time = current_time - initial_time
    if (elasped_time > 10 * i):
        playsound('Question' + str(i) + '.mp3')
        print('Playing Question ' + str(i))
        i += 1

print('You have reached the end of the test. Thank you for your participation.')