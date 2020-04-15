# csci499_patriya-piyawiroj

## Environment
Using Vagrant box: ubuntu/bionic64 (virtualbox, 20190109.0.0)

## Set-up
The previous installation instructions in the README.md from Phase 1 was moved to INSTALL.md\n
Set up can be done using the following scripts (based off previous README) or the full instructions found in INSTALL.md

```
./install.sh                # installs prerequisites: some lines may not run and have to be installed manually
./install_grpc.sh           # installs grpc and subdirectories
./install_lib.sh            # other third-party
```

In root directory, compile with the following
```
cmake .
make
```

## Running

### Phase 2: Persistence

Note: the kvtest executable is not a unit test suite but can be used to test persistant functionality (see example and class comments for more details) 

Example:
```
#in csci499_patriya-piyawiroj/store
./key_value_store_server                         # optionally with -store {file_name} 
./kvtest -key {any_key} -value {any_string}      # will store a given key and value to store, and optionally to given file
```

***IMPORTANT: If client (./kvtest) dooes not terminate immediately after completing put, stop process and run again or reboot VM***
