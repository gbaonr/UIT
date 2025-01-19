from ortools.algorithms.python import knapsack_solver
import requests
import time

# function to import .kp file
def import_file(url):
    response = requests.get(url)
    if response.status_code == 200:
        file_lines = response.text.split('\n')
        file_content_list = [[int(num) for num in line.split()] for line in file_lines if line]

        return file_content_list
    else:
        return None


# Function to create a list of valid  urls to specified .kp file number
def get_urls(kp): 

    link =  r"https://raw.githubusercontent.com/likr/kplib/master/" 

    groups = ['00Uncorrelated', '01WeaklyCorrelated', '02StronglyCorrelated',   '03InverseStronglyCorrelated', '04AlmostStronglyCorrelated', '05SubsetSum',   '06UncorrelatedWithSimilarWeights', '07SpannerUncorrelated',  '08SpannerWeaklyCorrelated', '09SpannerStronglyCorrelated',  '10MultipleStronglyCorrelated', '11ProfitCeiling', '12Circle']

    url_list = []
    Ncapacities = []
    
    kpfile = "s0" + str(kp) + ".kp" if kp > 9 else "s00" + str(kp) + ".kp"

    for i in (50, 100, 200, 500, 1000):
        if i < 100:
            n = 'n000' + str(i)
        elif i < 1000:
            n = 'n00' + str(i)
        else:
            n = 'n0' + str(i)
        Ncapacities.append(n)

    for group in groups:
        for Ncapacity in Ncapacities:
            url = link + f'{group}/{Ncapacity}/R01000/{kpfile}'
            # print(url)
            url_list.append(url)
    
    return url_list


# Function to test if any url is not gud 
def test_urls(urls):
    for index, url in enumerate(urls):
        file_ = import_file(url)
        if file_ is not None:
            print(f"url {index+1} passed")
        else:
            print(f"*******url {index+1}: {url} ERROR")


# fucntion to solve knapsack problem
def solve_kp(url):
    output = url.replace("https://raw.githubusercontent.com/likr/kplib/master/", "") 
    file_content = import_file(url)
    
    if file_content is None: 
        output += "\n   Import content failed !!\n\n"
        return output
    
    solver = knapsack_solver.KnapsackSolver(
                knapsack_solver.SolverType. KNAPSACK_MULTIDIMENSION_BRANCH_AND_BOUND_SOLVER, "KnapsackExample",)

    values = [value[0] for value in file_content[2:]]
    # print("\nValues = \n", values)
    # output += "\nValue = \n" + str(values)
    

    weights = [[weight[1] for weight in file_content[2:]]]
    # output += "\nWeights = \n" + str(weights) 

    capacities = file_content[1]
    output += "\n   Capacities = " + str(capacities)
    
    time_limit = 180 # 3 minutes

    solver.set_time_limit(time_limit)  # milliseconds
    solver.init(values, weights, capacities)

    start_time = time.time()

    computed_value = solver.solve()

    elapsed_time = time.time() - start_time

    # If time exceed, stop 

    #calculate
    if computed_value == -1:
        output += "Solver didn't find any solution (or exceeded time limit)"
    else:
        packed_items = []
        packed_weights = []
        total_weight = 0

        for i in range(len(values)):
            if solver.best_solution_contains(i):
                packed_items.append(i)
                packed_weights.append(weights[0][i])
                total_weight += weights[0][i]

        output += "\n   Total weight: " + str(total_weight) 
        output += "\n   Total value: " + str(computed_value) 
        output += "\n   Elapsed time: " + str(elapsed_time) + "\n\n"
    
    return output

        

# Create the list of urls to s005.kp files of all groups
urls = get_urls(5)

# solve knapsack problem of every url and write result in answer.txt
with open("answer.txt", "w+") as file:
    for index, url in enumerate(urls):
        output = solve_kp(url)
        file.write(output)
        print(f"Done link: {index+1}")


        
    