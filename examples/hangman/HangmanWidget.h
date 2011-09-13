// This may look like C code, but it's really -*- C++ -*-
/* 
 * Copyright (C) 2011 Emweb bvba, Heverlee, Belgium
 *
 * See the LICENSE file for terms of use.
 */

#ifndef HANGMAN_WIDGET_H_
#define HANGMAN_WIDGET_H_

#include <vector>

#include <Wt/WContainerWidget>

#include "Dictionary.h"

namespace Wt {
  class WText;
  class WPushButton;
}

class Session;
class WordWidget;
class ImagesWidget;
class LettersWidget;

class HangmanWidget: public Wt::WContainerWidget
{
public:
  HangmanWidget(const std::string &name, 
		Dictionary dictionary, 
		Wt::WContainerWidget *parent = 0);

  Wt::Signal<int>& updateScore() { return updateScore_; }
  
private:
  Wt::WText                     *title_;

  WordWidget                    *word_;
  ImagesWidget                  *images_;
  LettersWidget                 *letters_;

  Wt::WText                     *statusText_;
  Wt::WPushButton               *newGameButton_;
  
  Wt::Signal<int>                updateScore_;

  std::string                    name_;
  Dictionary                     dictionary_;
  
  void registerGuess(char c);

  void newGame();
};

#endif //HANGMAN_WIDGET_H_
