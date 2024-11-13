from concurrent.futures import ThreadPoolExecutor

def find_divisors(n):
	return [i for i in range(1, n + 1) if n % i == 0]

def slow_function():
	print("Slow thread started")
	try:
		return find_divisors(1000000000)
	finally:
		print("Slow thread ended")

def fast_function():
	print("Fast thread started")
	try:
		return find_divisors(500000000)
	finally:
		print("Fast thread ended")

def main():
	with ThreadPoolExecutor() as executor:
		executor.submit(slow_function)
		executor.submit(fast_function)

if __name__ == "__main__":
	main()