import time

# Homemade version of matlab tic and toc functions
def tic():
    #print =("Start")
    global startTime_for_tictoc
    startTime_for_tictoc = time.time()

def toc():
    if 'startTime_for_tictoc' in globals():
        #print("You took " + str(round((time.time() - startTime_for_tictoc),1)) + " seconds to answer the question.")
        pass
    else: print("Toc: start time not set")

    return round((time.time() - startTime_for_tictoc),1)