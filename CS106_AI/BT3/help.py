from ortools.algorithms.python import knapsack_solver
import requests
import time


def import_file_from_github(username, repository, branch, file_path):
    # Construct the raw URL of the file on GitHub
    url = f"https://raw.githubusercontent.com/{username}/{repository}/{branch}/{file_path}"

    # Make a GET request to retrieve the content of the file
    response = requests.get(url)
    print(url)

    # Check if request was successful
    if response.status_code == 200:
        # Split the content of the file by newline characters to create a list of lines
        file_lines = response.text.split('\n')

        # Split each line by space and convert each element to integer
        file_content_list = [[int(num) for num in line.split()]
                             for line in file_lines if line]

        return file_content_list
    else:
        # If request failed, print an error message
        print(
            f"Failed to retrieve the file from {url}. Status code: {response.status_code}")
        return None


def main():
    # File import parameters
    username = "likr"
    repository = "kplib"
    branch = "master"
    file_path = "00Uncorrelated/n00050/R01000/s004.kp" # change to the path that you want

    file_content = import_file_from_github(
        username, repository, branch, file_path)

    if file_content is not None:
        # print("File content:")
        # # print(file_content)
        # print(file_content)

        solver = knapsack_solver.KnapsackSolver(
            knapsack_solver.SolverType.KNAPSACK_MULTIDIMENSION_BRANCH_AND_BOUND_SOLVER, "KnapsackExample",)

        values = [value[0] for value in file_content[2:]]
        print("\nValues = \n", values)

        weights = [[weight[1] for weight in file_content[2:]]]
        print("\nWeights = \n", weights)

        capacities = file_content[1]
        print("\nCapacities = ", capacities)

        solver.init(values, weights, capacities)

        time_limit = 180  # 3 minutes
        start_time = time.time()
        solver.set_time_limit(time_limit * 1000)  # milliseconds

        computed_value = solver.solve()

        elapsed_time = time.time() - start_time

        if computed_value == -1:
            print("Solver didn't find any solution (or exceeded time limit)")
        else:
            packed_items = []
            packed_weights = []
            total_weight = 0
            print("Total value =", computed_value)
            for i in range(len(values)):
                if solver.best_solution_contains(i):
                    packed_items.append(i)
                    packed_weights.append(weights[0][i])
                    total_weight += weights[0][i]
            print("Total weight:", total_weight)
            print("Packed items:", packed_items)
            print("Packed_weights:", packed_weights)

            print("Elapsed time:", elapsed_time, "seconds")

    else:
        print("Failed to import the file.")


if __name__ == "__main__":
    main()
