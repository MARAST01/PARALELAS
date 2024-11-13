import time

def sleeper():
	time.sleep(1.75)

def spinlock():
	for _ in range(100000000):
		pass

for function in (sleeper, spinlock):
	t1 = time.perf_counter(), time.process_time()
	function()
	t2 = time.perf_counter(), time.process_time()
	print(f"{function.__name__}()")
	print(t2[0] - t1[0], t2[1] - t1[1])

print(f"Tiempo de CPU: {t2[1] - t1[1]:.2f} segundos")
