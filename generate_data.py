import csv

filename = "large_data.csv"
num_rows = 1_000_000

print(f"generating {num_rows} rows in {filename}")
header = ["timestamp","price","volume"]

with open(filename, "w" , newline="") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(header)
    for i in range (num_rows):
        timestamp = f"2025-07-09T14:00:{i:02d}"
        price = 100.0 + (i * 0.01)
        volume = 50 + (i % 100)
        writer.writerow([timestamp, price, volume])
        
print("done")
