# realistic_data_generator.py
import csv
import math
import random

# --- Configuration ---
filename = "large_data.csv"
num_rows = 1_000_000
initial_price = 100.0

# --- Trend Parameters ---
# Overall upward trend
drift = 0.0001

# Sine wave parameters for cycles
# 'amplitude' controls how high and low the cycles go.
amplitude = 2.0
# 'frequency' controls how often the cycles occur.
frequency = 0.001

# Noise parameter for daily fluctuations
noise_strength = 0.25

print(f"Generating {num_rows} rows of more realistic data in {filename}...")

header = ["timestamp", "price", "volume"]

with open(filename, "w", newline="") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(header)

    for i in range(num_rows):
        # 1. Calculate the sine wave component for the cycle
        sine_component = amplitude * math.sin(frequency * i)

        # 2. Calculate the random noise
        noise = random.uniform(-noise_strength, noise_strength)

        # 3. Combine all components to get the final price
        price = initial_price + (i * drift) + sine_component + noise

        # Ensure price doesn't go below a certain threshold (e.g., 1.0)
        price = max(1.0, price)

        timestamp = f"T{i+1}" # Simple timestamp
        volume = random.randint(50, 200)

        writer.writerow([timestamp, f"{price:.2f}", volume])

print("Done.")

