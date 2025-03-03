#include <benchmark/benchmark.h>
#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/caesar/caesar_algo.h>
#include <impl/playfair/playfair_algo.h>
#include <impl/rc4/rc4_algo.h>
#include <impl/viginer/viginer_algo.h>
#include <impl/vernam/vernam_algo.h>
#include <impl/atbash/atbash_algo.h>
#include <impl/trithemius/trithemius_algo.h>
#include "helper.h"

const std::string input = genString(100);

static void BM_CaesarCipher_Encode(benchmark::State &state) {
    coded::impl::caesar::CaesarCipherAlgo algo(10);
    const core::Encoder &encoder = algo.GetEncoder();
    for (auto _ : state) {
        encoder.Encode(input);
    }
}

BENCHMARK(BM_CaesarCipher_Encode);

static void BM_CaesarCipher_Decode(benchmark::State &state) {
    coded::impl::caesar::CaesarCipherAlgo algo(10);
    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
}

BENCHMARK(BM_CaesarCipher_Decode);

// Playfair
static void BM_PlayfairCipher_Encode(benchmark::State &state) {
    coded::impl::playfair::PlayfairCipherAlgo algo;
    algo.genSalt();

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
}

BENCHMARK(BM_PlayfairCipher_Encode);

static void BM_PlayfairCipher_Decode(benchmark::State &state) {
    coded::impl::playfair::PlayfairCipherAlgo algo;
    algo.genSalt();

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
}

BENCHMARK(BM_PlayfairCipher_Decode);

// RC4
static void BM_RC4_Encode(benchmark::State &state) {
    coded::impl::rc4::RC4Algo algo(genString(10));

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
}

BENCHMARK(BM_RC4_Encode);

static void BM_RC4_Decode(benchmark::State &state) {
    coded::impl::rc4::RC4Algo algo(genString(10));

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
}

BENCHMARK(BM_RC4_Decode);

// Vigenere
static void BM_Vigenere_Encode(benchmark::State &state) {
    coded::impl::viginer::ViginerAlgo algo(genString(10));

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
}

BENCHMARK(BM_Vigenere_Encode);

static void BM_Vigenere_Decode(benchmark::State &state) {
    coded::impl::viginer::ViginerAlgo algo(genString(10));

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
}

BENCHMARK(BM_Vigenere_Decode);

// Vernam
static void BM_Vernam_Encode(benchmark::State &state) {
    coded::impl::vernam::VernamAlgo algo(genString(10));

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
}

BENCHMARK(BM_Vernam_Encode);

static void BM_Vernam_Decode(benchmark::State &state) {
    coded::impl::vernam::VernamAlgo algo(genString(10));

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
}

BENCHMARK(BM_Vernam_Decode);

// Atbash
static void BM_Atbash_Encode(benchmark::State &state) {
    coded::impl::atbash::AtbashCipherAlgo algo;

    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
}

BENCHMARK(BM_Atbash_Encode);

static void BM_Atbash_Decode(benchmark::State &state) {
    coded::impl::atbash::AtbashCipherAlgo algo;

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
}

BENCHMARK(BM_Atbash_Decode);

// Trithmeius
static void BM_Trithemius_Encode(benchmark::State &state) {
    coded::impl::trithemius::TrithemiusCipherAlgo algo;
    const core::Encoder &encoder = algo.GetEncoder();

    for (auto _ : state) {
        encoder.Encode(input);
    }
}

BENCHMARK(BM_Trithemius_Encode);

static void BM_Trithemius_Decode(benchmark::State &state) {
    coded::impl::trithemius::TrithemiusCipherAlgo algo;

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    std::string encoded = encoder.Encode(input);
    for (auto _ : state) {
        decoder.Decode(encoded);
    }
}

BENCHMARK(BM_Trithemius_Decode);


BENCHMARK_MAIN();
