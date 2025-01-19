import subprocess
import time
from pacman import GameState
def run(lay,seed,alg):
    layout = lay + "Classic"
    algorithm = alg + "Agent"
    depth = 3
    eval = "myEvalFunc"
    seed = str(22520109 + seed)
    frameTime = 0

    command = f"python pacman.py -l {layout} -p {algorithm} -a depth={depth},evalFn={eval} -s {seed} --frameTime {frameTime}" 

    subprocess.call(command, shell=True)


layouts =["capsule", "contest", "medium", "minimax", "open", "original", "power", "small", "test", "trapped", "tricky"]

chosenLayouts = ["capsule", "contest", "medium", "minimax", "trapped", "open"]

alg = "Expectimax"

with open(alg + "Agent_default.txt", "w+") as file:
    file.write(alg + "\n\n")
    for lay in (chosenLayouts):
        file.write(str("\t" + lay + "Classic: \n" ))
        res = ""
        for i in range(0,5):
            res = str("\t\t" + "seed: 22520109+" +str(i) + ": ")
            file.write(res)
            run(lay, i, alg)
            state = ""
            with open("result.txt", "r") as result:
                for line in result:
                    state += line.replace("\n","")  + "; "
                state += "\n"
            file.write(state)

# run("open",3, alg)

        
