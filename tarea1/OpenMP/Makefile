all: omp_ex

omp_ex: omp_ex.cpp
	g++ -fopenmp omp_ex.cpp -o omp_ex
	sbatch submit.slurm

clean:
	rm -f omp_ex



jae:
	echo "Hello World"
