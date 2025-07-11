import csv
import random
import datetime

# --- Configuration ---
filename = "large_data.csv"
num_rows = 1_000_000
start_date = datetime.datetime(2025, 7, 9, 14, 0, 0)

# --- Price Configuration ---
# Starting price for the random walk
initial_price = 100.0
# The general direction of the price (a small positive value for an upward trend)
drift = 0.001
# The volatility or "randomness" of the price steps
volatility = 0.1
# Price boundaries
min_price = 50.0
max_price = 150.0


# --- Volume Configuration ---
# Base volume range
base_volume_min = 50
base_volume_max = 300
# Chance of a volume spike (e.g., 2%)
spike_chance = 0.02
# Volume range during a spike
spike_volume_min = 500
spike_volume_max = 2500


print(f"Generating {num_rows} rows of realistic data in '{filename}'...")

# --- Data Generation ---
header = ["timestamp", "price", "volume"]
current_price = initial_price

with open(filename, "w", newline="") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(header)

    for i in range(num_rows):
        # --- Generate Timestamp ---
        # Correctly increment time by one second for each row
        current_time = start_date + datetime.timedelta(seconds=i)
        timestamp_str = current_time.isoformat()

        # --- Generate Price (Random Walk) ---
        # Calculate a random step with a slight upward drift
        random_step = random.uniform(-volatility, volatility)
        current_price += drift + random_step

        # Gently push the price back if it nears the boundaries
        if current_price > max_price:
            current_price += random.uniform(-volatility, -0.1) # Nudge down
        elif current_price < min_price:
            current_price += random.uniform(0.1, volatility) # Nudge up
        
        # Ensure price stays strictly within bounds
        current_price = max(min_price, min(current_price, max_price))


        # --- Generate Volume ---
        # Decide if this row should have a volume spike
        if random.random() < spike_chance:
            volume = random.randint(spike_volume_min, spike_volume_max)
        else:
            volume = random.randint(base_volume_min, base_volume_max)

        # Write the new row to the CSV file
        writer.writerow([timestamp_str, f"{current_price:.2f}", volume])

print("Done.")

