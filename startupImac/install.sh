curl https://raw.githubusercontent.com/sanelesazi/startupImac/master/vimrc_settings.txt >> ~/.vimrc
curl https://raw.githubusercontent.com/sanelesazi/startupImac/master/zshrc_setting.txt >> ~/.zshrc
source ~/.zshrc
echo "Applied zsh and vim settings"
open -a /Applications/Slack.app
echo "Check For Slack..."
open -a /Applications/Backup\ and\ Sync.app
echo "Check Google Backup and Sync..."
open -a /Applications/Google\ Chrome.app
echo "Check Chrome..."
open -a /Applications/iTerm.app
echo "Check iTerm2"
echo "Use alias - 'gccw' for gcc -Wall -Wextra -Werror to compile"
sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
echo "Installing brew..."
brew install valgrind
echo "Done! :-)"
echo "relaunch terminal"
exit

