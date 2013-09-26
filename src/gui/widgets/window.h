/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
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

#ifndef GUI_WIDGETS_WINDOW_H
#define GUI_WIDGETS_WINDOW_H

#include "render/graphics.h"

#include "gui/widgets/widget2.h"

#include <guichan/widgetlistener.hpp>

#include <guichan/widgets/window.hpp>

#include "localconsts.h"

class ContainerPlacer;
class ImageCollection;
class Layout;
class LayoutCell;
class Skin;
class WindowContainer;

/**
 * A window. This window can be dragged around and has a title bar. Windows are
 * invisible by default.
 *
 * \ingroup GUI
 */
class Window : public gcn::Window,
               public Widget2,
               private gcn::WidgetListener
{
    public:
        /**
         * Constructor. Initializes the title to the given text and hooks
         * itself into the window container.
         *
         * @param caption The initial window title, "Window" by default.
         * @param modal   Block input to other windows.
         * @param parent  The parent window. This is the window standing above
         *                this one in the window hiearchy. When reordering,
         *                a window will never go below its parent window.
         * @param skin    The location where the window's skin XML can be found.
         */
        Window(const std::string &caption = "Window", const bool modal = false,
               Window *const parent = nullptr, std::string skin = "");

        A_DELETE_COPY(Window)

        /**
         * Destructor. Deletes all the added widgets.
         */
        virtual ~Window();

        /**
         * Sets the window container to be used by new windows.
         */
        static void setWindowContainer(WindowContainer *const windowContainer);

        /**
         * Draws the window.
         */
        void draw(gcn::Graphics *graphics) override;

        /**
         * Sets the size of this window.
         */
        void setContentSize(int width, int height);

        /**
         * Sets the location relative to the given widget.
         */
        void setLocationRelativeTo(const gcn::Widget *const widget);

        /**
         * Sets the location relative to the given widget (only horisontally)
         */
        void setLocationHorisontallyRelativeTo(const gcn::Widget
                                               *const widget);

        /**
         * Sets the location relative to the given enumerated position.
         */
        void setLocationRelativeTo(const ImageRect::ImagePosition &position,
                                   int offsetX = 0, int offsetY = 0);

        /**
         * Sets whether or not the window can be resized.
         */
        void setResizable(const bool resize);

        void redraw();

        /**
         * Called whenever the widget changes size.
         */
        virtual void widgetResized(const gcn::Event &event) override;

        virtual void widgetMoved(const gcn::Event& event) override;

        /**
         * Called whenever the widget is hidden.
         */
        virtual void widgetHidden(const gcn::Event &event) override;

        /**
         * Sets whether or not the window has a close button.
         */
        void setCloseButton(const bool flag);

        /**
         * Returns whether the window can be resized.
         */
        bool isResizable() const A_WARN_UNUSED;

        /**
         * Sets the minimum width of the window.
         */
        void setMinWidth(const int width);

        int getMinWidth() const A_WARN_UNUSED
        { return mMinWinWidth; }

        /**
         * Sets the minimum height of the window.
         */
        void setMinHeight(const int height);

        int getMinHeight() const A_WARN_UNUSED
        { return mMinWinHeight; }

        /**
         * Sets the maximum width of the window.
         */
        void setMaxWidth(const int width);

        int getMaxWidth() const A_WARN_UNUSED
        { return mMaxWinWidth; }

        /**
         * Sets the minimum height of the window.
         */
        void setMaxHeight(const int height);

        int getMaxHeight() const A_WARN_UNUSED
        { return mMaxWinHeight; }

        /**
         * Sets flag to show a title or not.
         */
        void setShowTitle(bool flag)
        { mShowTitle = flag; }

        /**
         * Sets whether or not the window has a sticky button.
         */
        void setStickyButton(const bool flag);

        /**
          * Sets whether the window is sticky. A sticky window will not have
          * its visibility set to false on a general setVisible(false) call.
          * Use this to set the default before you call loadWindowState().
          */
        void setSticky(const bool sticky);

        /**
         * Returns whether the window is sticky.
         */
        bool isSticky() const A_WARN_UNUSED
        { return mSticky; }

        /**
          * Sets whether the window sticky mean window locked or not.
          */
        void setStickyButtonLock(const bool sticky);

        /**
         * Returns whether the window sticky locking window.
         */
        bool isStickyButtonLock() const A_WARN_UNUSED
        { return mStickyButtonLock; }

        /**
         * Overloads window setVisible by Guichan to allow sticky window
         * handling.
         */
        virtual void setVisible(bool visible);

        /**
         * Overloads window setVisible by Guichan to allow sticky window
         * handling, or not, if you force the sticky state.
         */
        void setVisible(const bool visible, const bool forceSticky);

        /**
         * Returns whether the window is visible by default.
         */
        bool isDefaultVisible() const A_WARN_UNUSED
        { return mDefaultVisible; }

        /**
         * Sets whether the window is visible by default.
         */
        void setDefaultVisible(const bool save)
        { mDefaultVisible = save; }

        /**
         * Returns whether the window will save it's visibility.
         */
        bool willSaveVisible() const
        { return mSaveVisible; }

        /**
         * Sets whether the window will save it's visibility.
         */
        void setSaveVisible(const bool save)
        { mSaveVisible = save; }

        /**
         * Returns the parent window.
         *
         * @return The parent window or <code>NULL</code> if there is none.
         */
        Window *getParentWindow() const
        { return mParent; }

        /**
         * Schedule this window for deletion. It will be deleted at the start
         * of the next logic update.
         */
        virtual void scheduleDelete();

        /**
         * Starts window resizing when appropriate.
         */
        void mousePressed(gcn::MouseEvent &event) override;

        /**
         * Implements window resizing and makes sure the window is not
         * dragged/resized outside of the screen.
         */
        void mouseDragged(gcn::MouseEvent &event) override;

        /**
         * Implements custom cursor image changing context, based on mouse
         * relative position.
         */
        void mouseMoved(gcn::MouseEvent &event) override;

        /**
         * When the mouse button has been let go, this ensures that the mouse
         * custom cursor is restored back to it's standard image.
         */
        void mouseReleased(gcn::MouseEvent &event) override;

        /**
         * When the mouse leaves the window this ensures that the custom cursor
         * is restored back to it's standard image.
         */
        void mouseExited(gcn::MouseEvent &event) override;

        void mouseEntered(gcn::MouseEvent &event) override;

        void updateResizeHandler(gcn::MouseEvent &event);

        /**
         * Sets the name of the window. This is not the window title.
         */
        void setWindowName(const std::string &name)
        { mWindowName = name; }

        /**
         * Returns the name of the window. This is not the window title.
         */
        const std::string &getWindowName() const A_WARN_UNUSED
        { return mWindowName; }

        /**
         * Reads the position (and the size for resizable windows) in the
         * configuration based on the given string.
         * Uses the default values when config values are missing.
         * Don't forget to set these default values and resizable before
         * calling this function.
         */
        void loadWindowState();

        /**
         * Saves the window state so that when the window is reloaded, it'll
         * maintain its previous state and location.
         */
        void saveWindowState();

        /**
         * Set the default win pos and size.
         * (which can be different of the actual ones.)
         */
        void setDefaultSize(const int defaultX, const int defaultY,
                            int defaultWidth, int defaultHeight);

        /**
         * Set the default win pos and size to the current ones.
         */
        void setDefaultSize();

        /**
         * Set the default win pos and size.
         * (which can be different of the actual ones.)
         * This version of setDefaultSize sets the window's position based
         * on a relative enumerated position, rather than a coordinate position.
         */
        void setDefaultSize(const int defaultWidth, const int defaultHeight,
                            const ImageRect::ImagePosition &position,
                            const int offsetx = 0, const int offsetY = 0);

        /**
         * Reset the win pos and size to default. Don't forget to set defaults
         * first.
         */
        virtual void resetToDefaultSize();

        /**
         * Adjusts the window position after the application window has been
         * resized.
         */
        void adjustPositionAfterResize(const int oldScreenWidth,
                                       const int oldScreenHeight);

        /**
         * Gets the layout handler for this window.
         */
        Layout &getLayout() A_WARN_UNUSED;

        /**
         * Clears the window's layout (useful for redesigning the window). Does
         * not delete the widgets!
         */
        void clearLayout();

        /**
         * Computes the position of the widgets according to the current
         * layout. Resizes the window so that the layout fits. Deletes the
         * layout.
         * @param w if non-zero, force the window to this width.
         * @param h if non-zero, force the window to this height.
         * @note This function is meant to be called with fixed-size windows.
         */
        void reflowLayout(int w = 0, int h = 0);

        /**
         * Adds a widget to the window and sets it at given cell.
         */
        LayoutCell &place(const int x, const int y, gcn::Widget *const wg,
                          const int w = 1, const int h = 1);

        /**
         * Returns a proxy for adding widgets in an inner table of the layout.
         */
        ContainerPlacer getPlacer(const int x, const int y) A_WARN_UNUSED;

        /**
         * Positions the window in the center of it's parent.
         */
        void center();

        /**
         * Positions the window in the horisontal center of it's parent.
         */
        void centerHorisontally();

        /**
         * Overrideable functionality for when the window is to close. This
         * allows for class implementations to clean up or do certain actions
         * on window close they couldn't do otherwise.
         */
        virtual void close();

         /**
         * Allows the windows modal status to change
         */
        void setModal(const bool modal);

        /**
         * Gets the alpha value used by the window, in a GUIChan usable format.
         */
        int getGuiAlpha() const A_WARN_UNUSED;

        gcn::Rectangle getWindowArea() const A_WARN_UNUSED;

        bool isResizeAllowed(const gcn::MouseEvent &event) const A_WARN_UNUSED;

        void setCaptionFont(gcn::Font *font)
        { mCaptionFont = font; }

        void enableVisibleSound(bool b)
        { mPlayVisibleSound = b; }

        bool isWindowVisible() const A_WARN_UNUSED
        { return mVisible; }

#ifdef USE_PROFILER
        virtual void logic();
#endif

    protected:
        bool canMove() const A_WARN_UNUSED;

        int getOption(const std::string &name,
                      const int def = 0) const A_WARN_UNUSED;

        bool getOptionBool(const std::string &name) const A_WARN_UNUSED;

        void setTitlePadding(int p)
        { mTitlePadding = p; }

        int getTitlePadding() const A_WARN_UNUSED
        { return mTitlePadding; }

        Skin *mSkin;                  /**< Skin in use by this window */
        int mDefaultX;                /**< Default window X position */
        int mDefaultY;                /**< Default window Y position */
        int mDefaultWidth;            /**< Default window width */
        int mDefaultHeight;           /**< Default window height */
        bool mRedraw;
        bool mLastRedraw;

    private:
        enum ResizeHandles
        {
            TOP    = 0x01,
            RIGHT  = 0x02,
            BOTTOM = 0x04,
            LEFT   = 0x08,
            CLOSE  = 0x10
        };

        /**
         * Ensures the window is on the screen, moving it if necessary. This is
         * used by loadWindowState and setVisible(true), and when the screen
         * is resized.
         */
        void ensureOnScreen();

        /**
         * Determines if the mouse is in a resize area and returns appropriate
         * resize handles. Also initializes drag offset in case the resize
         * grip is used.
         *
         * @see ResizeHandles
         */
        int getResizeHandles(const gcn::MouseEvent &event) A_WARN_UNUSED;

        Image *mGrip;                 /**< Resize grip */
        Window *mParent;              /**< The parent window */
        Layout *mLayout;              /**< Layout handler */
        gcn::Rectangle mCloseRect;    /**< Close button rectangle */
        gcn::Rectangle mStickyRect;   /**< Sticky button rectangle */
        gcn::Rectangle mGripRect;     /**< Resize grip rectangle */
        std::string mWindowName;      /**< Name of the window */
        int mMinWinWidth;             /**< Minimum window width */
        int mMinWinHeight;            /**< Minimum window height */
        int mMaxWinWidth;             /**< Maximum window width */
        int mMaxWinHeight;            /**< Maximum window height */

        static int mouseResize;       /**< Active resize handles */
        static int windowInstances;   /**< Number of Window instances */


        /**
         * The width of the resize border. Is independent of the actual window
         * border width, and determines mostly the size of the corner area
         * where two borders are moved at the same time.
         */
        static const unsigned resizeBorderWidth = 10;
        ImageCollection *mVertexes;
        int mCaptionOffsetX;
        int mCaptionOffsetY;
        gcn::Graphics::Alignment mCaptionAlign;
        int mTitlePadding;
        int mGripPadding;
        int mResizeHandles;
        int mOldResizeHandles;
        gcn::Font *mCaptionFont;
        bool mShowTitle;              /**< Window has a title bar */
        bool mModal;                  /**< Window is modal */
        bool mCloseWindowButton;      /**< Window has a close button */
        bool mDefaultVisible;         /**< Window's default visibility */
        bool mSaveVisible;            /**< Window will save visibility */
        bool mStickyButton;           /**< Window has a sticky button */
        bool mSticky;                 /**< Window resists hiding*/
        bool mStickyButtonLock;       /**< Window locked if sticky enabled*/
        bool mPlayVisibleSound;
};

#endif  // GUI_WIDGETS_WINDOW_H
