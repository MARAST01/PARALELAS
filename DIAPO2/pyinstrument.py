from pyinstrument import Profiler
from random import uniform

def estimate_pi(n):
	return 4 * sum(hits(point()) for _ in range(n)) / n

def hits(point):
	return abs(point) <= 1

def point():
	return complex(uniform(0, 1), uniform(0, 1))



with Profiler(interval=0.1) as profiler:
	estimate_pi(n=1000000)