import React from 'react';
import { render, screen, fireEvent, RenderResult, Queries, RenderOptions } from '@testing-library/react';
import { ThemeProvider } from 'styled-components';
import { theme } from '@gymshark/utils';
import reduce from 'lodash/reduce';

type AdditionalThemes = { [key: string]: unknown }[];
type ContextConfigs<T> = { context: React.Context<T>; value: T; order: number }[];

let themes: AdditionalThemes;
let configs: ContextConfigs<any>;

const WrappedInTheme = ({ children }: { children: JSX.Element }): JSX.Element => {
    let output: JSX.Element;

    const reducer = <G extends {}>(acc: JSX.Element, next: { context: React.Context<G>; value: G }): JSX.Element => {
        const { context: Context, value } = next;
        return <Context.Provider value={value}> {acc} </Context.Provider>;
    };

    if (configs && configs.length) {
        // Sort by order prop first
        configs.sort((a, b) => a.order - b.order);
        output = reduce(configs, reducer, <ThemeProvider theme={{ ...theme, ...themes }}>{children}</ThemeProvider>);
    } else {
        output = <ThemeProvider theme={{ ...theme, ...themes }}>{children}</ThemeProvider>;
    }
    return output;
};

const customRender = <T extends {}>(
    ui: JSX.Element,
    additionalThemes: AdditionalThemes = [],
    contextConfigs: ContextConfigs<T>,
): RenderResult<Queries, HTMLElement> => {
    // Wipe before assignment to avoid pollution using global vars at
    themes = [];
    configs = [];
    // Reassign to function params
    themes = Object.assign({}, ...additionalThemes);
    configs = contextConfigs;

    return render(ui, { wrapper: WrappedInTheme } as RenderOptions<Queries, HTMLElement>);
};

export * from '@testing-library/react';

// Override render method - rexporting screen and fireEvent as a stop gap solution
export { customRender as render, screen, fireEvent };
