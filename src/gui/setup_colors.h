/*
 *  Configurable text colors
 *  Copyright (C) 2008  Douglas Boffey <dougaboffey@netscape.net>
 *  Copyright (C) 2011-2013  The ManaPlus Developers
 *
 *  This file is part of The ManaPlus Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SETUP_COLORS_H
#define SETUP_COLORS_H

#include "gui/widgets/setuptab.h"

#include <guichan/actionlistener.hpp>
#include <guichan/selectionlistener.hpp>

#include <string>

class BrowserBox;
class Label;
class ListBox;
class ScrollArea;
class Slider;
class TextField;
class TextPreview;

class Setup_Colors final : public SetupTab,
                           public gcn::SelectionListener
{
    public:
        explicit Setup_Colors(const Widget2 *const widget);

        A_DELETE_COPY(Setup_Colors)

        ~Setup_Colors();

        void apply() override;

        void cancel() override;

        void action(const gcn::ActionEvent &event) override;

        void valueChanged(const gcn::SelectionEvent &event) override;

    private:
        static const std::string rawmsg;

        ListBox *mColorBox;
        ScrollArea *mScroll;
        BrowserBox *mPreview;
        TextPreview *mTextPreview;
        ScrollArea *mPreviewBox;
        int mSelected;

        Label *mGradTypeLabel;
        Slider *mGradTypeSlider;
        Label *mGradTypeText;

        Label *mGradDelayLabel;
        Slider *mGradDelaySlider;
        TextField *mGradDelayText;

        Label *mRedLabel;
        Slider *mRedSlider;
        TextField *mRedText;
        int mRedValue;

        Label *mGreenLabel;
        Slider *mGreenSlider;
        TextField *mGreenText;
        int mGreenValue;

        Label *mBlueLabel;
        Slider *mBlueSlider;
        TextField *mBlueText;
        int mBlueValue;

        static void setEntry(Slider *const s, TextField *const t,
                             const int value);
        void updateColor();
        void updateGradType();
};

#endif  // SETUP_COLORS_H
