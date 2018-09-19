#!/usr/bin/env bash
unameOut="$(uname -s)"
case "${unameOut}" in
	Linux*)     machine=Linux;;
	Darwin*)    machine=Mac;;
	CYGWIN*)    machine=Cygwin;;
	MINGW*)     machine=MinGw;;
	*)          machine="UNKNOWN:${unameOut}"
esac
echo ${machine}

case "${machine}" in
	Linux)
		if !(dpkg -l | grep sdl) ;then

		fi
		;;
esac

case "${machine}" in
	Mac)
		echo Checking if Homebrew is installed
        if which -s brew > /dev/null ; then
            echo Homebrew already installed
            echo Installing dependencies
            if brew ls --versions pkg-config  > /dev/null; then
                echo pkg-config already installed
            else
                echo Installing pkg-config
                brew install pkg-config
            fi

            if brew ls --versions cmake > /dev/null; then
                echo cmake already installed
            else
                echo Installing cmake
                brew install cmake
            fi
            if brew ls --versions glew > /dev/null; then
                echo glew already installed
            else
                echo Installing glew
                brew install glew
            fi
            if brew ls --versions glm > /dev/null; then
                echo glm already installed
            else
                echo Installing glm
                brew install glm
            fi
        else
            echo Installing Homebrew
            sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
            echo Please open a new terminal and run "make" again.
        fi

		;;
esac