import time
from perf_sleep.pyperfsleep import PerfSleep

def test_thread_sleep(num_samples, nominal_sleep_time):
    perf_timer = PerfSleep()
    debug_data = []
    exceed_count = 0

    print(f"Sleeping for {nominal_sleep_time} seconds.")
    print(f"Sleeping for {int(nominal_sleep_time * 1e9)} nanoseconds.")

    for i in range(num_samples):
        start_time = time.perf_counter()
        
        perf_timer.thread_sleep(int(nominal_sleep_time * 1e9))  # Sleep for nominal_sleep_time seconds
        elapsed_time = time.perf_counter() - start_time
        debug_data.append(elapsed_time)

        if elapsed_time > nominal_sleep_time:  # Check if actual elapsed time exceeds nominal time
            exceed_count += 1

    return debug_data, exceed_count

if __name__ == "__main__":
    num_samples = 15
    nominal_sleep_time = 1e-5  # seconds
    debug_vector, exceed_count = test_thread_sleep(num_samples, nominal_sleep_time)

    # Calculate the differences
    differences = [abs(elapsed_time - nominal_sleep_time) for elapsed_time in debug_vector]

    # Print the minimum and maximum differences
    min_difference = min(differences)
    max_difference = max(differences)

    print("\nMinimum absolute difference:", min_difference)
    print("Maximum absolute difference:", max_difference)
    print("Number of times sleep exceeded nominal time:", exceed_count)
