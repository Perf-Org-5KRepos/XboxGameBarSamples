#pragma once

#include "Extension.g.h"
#include <winrt/Windows.UI.Xaml.Navigation.h>
#include <winrt/Microsoft.Gaming.XboxGameBar.h>

namespace winrt::UIExtSettingsSampleCPP::implementation
{
    struct Extension : ExtensionT<Extension>
    {
        Extension();

        virtual void OnNavigatedTo(winrt::Windows::UI::Xaml::Navigation::NavigationEventArgs e);

        // Settings click handler for ui extension settings click event
        Windows::Foundation::IAsyncAction SettingsButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& e);
      
    private:
        winrt::event_token m_settingsToken{};
        Microsoft::Gaming::XboxGameBar::XboxGameBarUIExtension m_uiExtension{ nullptr };
        Microsoft::Gaming::XboxGameBar::XboxGameBarExtensionControl m_extensionControl{ nullptr };
    };
}

namespace winrt::UIExtSettingsSampleCPP::factory_implementation
{
    struct Extension : ExtensionT<Extension, implementation::Extension>
    {
    };
}