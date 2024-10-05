#!/bin/bash
#SBATCH --job-name=cilk
#SBATCH --output=cilk.o%j
#SBATCH --partition=nu-wide
#SBATCH --ntasks=16
#SBATCH --time=00:05:00

cd $SLURM_SUBMIT_DIR

module load gcc/7.2.0
module load mpich/3.2.1-gcc-7.2.0
module load cmake/3.17.2

export CILK_NWORKERS=2

./mergesort_cilk
