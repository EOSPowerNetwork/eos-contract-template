# /bin/bash

# define contract name
Contract=mycontract

sed -i "s/contractacc/$Contract/gi" ./include/class1.hpp

sed -i "s/namespace contract_name/namespace $Contract/gi" ./include/class1.hpp

sed -i "s/namespace contract_name/namespace $Contract/gi" ./src/class1.cpp

sed -i "s/namespace contract_name/namespace $Contract/gi" ./schema/Schema1.hpp

sed -i "s/contract_name::/$Contract::/gi" ./include/class1.hpp

sed -i "s/contract_name::/$Contract::/gi" ./src/class1.cpp

sed -i "s/contract_name::/$Contract::/gi" ./test/test-contract_name.cpp

sed -i "s/contract_name::/$Contract::/gi" ./ricardian/class1-ricardian.cpp

sed -i "s/PROJ contract_name/PROJ $Contract/" ./CMakeLists.txt

sed -i "s/APPEND FILENAMES \"class1\"/APPEND FILENAMES \"$Contract\"/" ./CMakeLists.txt

sed -i "s/#include \"class1.hpp\"/#include \"$Contract.hpp\"/" ./ricardian/class1-ricardian.cpp

sed -i "s/#include \"class1.hpp\"/#include \"$Contract.hpp\"/" ./src/class1.cpp

sed -i "s/#include \"class1.hpp\"/#include \"$Contract.hpp\"/" ./test/test-class1.cpp

sed -i "s/class1_contract/$Contract\_contract/g" ./src/class1.cpp

sed -i "s/class1_contract/$Contract\_contract/g" ./include/class1.hpp

sed -i "s/contract_name.wasm/$Contract.wasm/" ./test/test-gnocityworks.cpp

mv ./src/class1.cpp ./src/$Contract.cpp

mv ./include/class1.hpp ./include/$Contract.hpp

mv ./ricardian/class1-ricardian.cpp ./ricardian/$Contract-ricardian.cpp

mv ./test/test-contract_name.cpp ./test/test-$Contract.cpp
