#!/bin/bash
#SBATCH --job-name=client-build
#SBATCH --partition=banana
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --exclusive
#SBATCH --time=00:03:00

make -C /clusterfs/ruzenkov/week15-16/client/Makefile

