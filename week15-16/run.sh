#!/bin/bash
#SBATCH --job-name=client-run
#SBATCH --partition=banana
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --exclusive
#SBATCH --time=00:03:00  # Увеличили время, чтобы приложение успело отработать
#SBATCH --array=0-4

make -C /clusterfs/ruzenkov/week15-16/client run
