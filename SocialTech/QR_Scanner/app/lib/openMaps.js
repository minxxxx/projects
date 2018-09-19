import React from 'react';
import { Linking, Platform } from 'react-native';

export default function open({latitude, longitude, zoomLevel, provider}) {
    createOpenLink({latitude, longitude, zoomLevel, provider})();
}

export function createOpenLink({latitude, longitude, zoomLevel, provider}) {
    if (!provider) {
        defaultProvider = (Platform.OS === 'ios') ? 'apple' : 'google';
    }
    const mapProvider = provider || defaultProvider;
    const mapLink = createMapLink({latitude, longitude, zoomLevel, provider: mapProvider});

    return () => {
        Linking.openURL(mapLink).catch((err) => {
            console.error('An error occured', err);
        });
    }
}

export function createMapLink({latitude, longitude, zoomLevel = 15, provider = 'google'}) {
    const link = {
		'google': `http://maps.google.com/maps?q=${latitude},${longitude}&z=${zoomLevel}`,
		'apple': `http://maps.apple.com/?sll=${latitude},${longitude}&z=${zoomLevel}`
	};

	return link[provider];
}