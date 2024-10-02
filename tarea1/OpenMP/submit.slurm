#!/bin/bash
#SBATCH --job-name=openmp
#SBATCH --output=openmp.o%j
#SBATCH --partition=nu-wide
#SBATCH --ntasks=16
#SBATCH --time=00:05:00

cd $SLURM_SUBMIT_DIR

module load gcc/7.2.0

export OMP_NUM_THREADS=4

./omp_ex
