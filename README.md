# ProcGenModels
Models for ProcGen Environment

To train the models, please use download the baseline_reward_shaping.ipynb notebook in this repo.
To run generate the plots, download all the log .csv files in the Gradescope submission and change to load the appropriate path. 


To execute the training command, please use this command below:
> python -m train_procgen.train --env_name fruitbot --num_levels 500 --distribution_mode easy 

To train with a larger convolution layer dimensions. Default is 16 16 32.
 > --conv_dim 32 32 64
 
To train with reward shaping use the flag below. Default is 0.
> --reward 1

To train with the RMSProp optimizer use the flag below. Default is adam. 
> --optimizer rmsprop

To change the director of the log files, use the flag below. Default is 'tmp/procgen'
> --log_dir "PATH_TO_FILE"
